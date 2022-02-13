Команда: Дарья Туричина, Владислав Мильшин, Александр Марьинский

## Read-Execute-Print-Loop
При старте программы запускатеся метод run() в readExecPrintLoop. Этот класс отвечает за считывание команд пользователя и возвращение ему результата исполнения или сообщения об ошибке. Метод run работает бесконечно пока мы не получили от пользователя команду exit. 

При получении команды от пользователя мы сперва осуществляем препроцессинг, потом исполнение команды, а потом выводим пользователю результат исполнения или сообщение об ошибке.

## Препроцессинг

В ходе препроцессинга из исходной строки получается preprocessedPipelineString - массив preprocessedCommandString, каждая из которых соответствует команде и представляет из себя массив строк (токенов), где нулевой элемент соответствует названию команды, а остальные считаются аргументами.
Препроцессинг происходит в методе createPreprocessedPipelineString класса preprocessor, который может кинуть исключение ParsingError. Исходная строка преобразуется в несколько этапов.

### Первая фаза

В первой фазе строка только разбивается на элементарные единицы. createPreprocessedPipelineString использует метод tokenize, который обрабатывает строку посимвольно слева направо. При обработке каждого символа обработчик находится в одном из состояний:
<ul>
<li>NO_QUOTE_OPEN</li>
<li>SINGLE_QUOTE_OPEN</li>
<li>DOUBLE_QUOTE_OPEN</li>
</ul>
Переходы между состояниями:
<ul>
<li>NO_QUOTE_OPEN<->SINGLE_QUOTE_OPEN при обработке символа '</li>
<li>NO_QUOTE_OPEN<->DOUBLE_QUOTE_OPEN при обработке символа "</li>
</ul>

Обработчик записывает символы в результирующий preprocessedPipelineString по правилам
<ol>
<li> в состоянии NO_QUOTE_OPEN
<ul>
<li>по пробельным символам ' \n\t' осуществляется переход к следующему токену в preprocessedCommandString, </li>
<li>по символу '|' осуществляется переход к следующему элементу типа preprocessedCommandString в preprocessedPipelineString, </li>
<li>пустые токены не пишутся в preprocessedCommandString, </li>
</ul>
</li>
<li> остальные символы в NO_QUOTE_OPEN и все символы (кроме соответствующих кавычек) в SINGLE_QUOTE_OPEN, DOUBLE_QUOTE_OPEN записываются в текущий токен, </li>
<li> символы перехода между состояниями и символы '| \n\t' в состоянии NO_QUOTE_OPEN не записываются в ответ. </li>
</ol>
Если исходная строка закончилась, но состояние не NO_QUOTE_OPEN или если в preprocessedPipelineString более одной preprocessedCommandString, но последняя пустая, tokenize бросает исключение ParsingError, которое через createPreprocessedPipelineString пробрасывается наружу в readExecPrintLoop.run().

### Вторая фаза

Вторая фаза реализует обработку переменных окружения. Переменные preprocessor хранит в поле variables типа variableStorage, который инкапсулирует работу с ними и предоставляет методы set(name, value), сохраняющий значение переменной, и get(name), который возвращает значение переменной, если оно было ранее сохранено, и пустую строку иначе. Имена переменных могут содержать только латинские буквы и цифры.

Сначала createPreprocessedPipelineString вызывает метод substitute(input), который подставляет значения переменных. substitute проходит по строке аналогично методу tokenize и если встречает символ '$' в состояниях NO_QUOTE_OPEN, DOUBLE_QUOTE_OPEN, то определяет имя переменной как подстроку от $ до первого символа, не являющегося латинской буквой или цифрой (или до конца строки), выписывает в ответ variables.get(variable_name) и продолжает процессинг со следующего в исходной строке после имени переменной символа. Таким образом подстановка происходит один раз в самом начале и циклы невозможны. 

Полученную после подстановок строку tokenizer разделяет на токены как и в первой фазе.

После разбиения на токены вызывается метод updateVariables, который обновляет значение переменных, если это необходимо. А именно: если в итоговой preprocessedPipelineString только одна preprocessedCommandString, а в ней только один токен и этот токен имеет вид [a-zA-Z][a-zA-Z0-9]\*=.\*, то часть токена до символа '=' считается названием переменной name, а после - новым значением value и вызывается variables.set(name, value). В противном случае проверяются все первые токены в preprocessedCommandString, на которые разбита preprocessedPipelineString, и если они удовлетвояют этому шаблону, то эти первые токены удаляются из ответа.

В принципе возможно такой парсинг выполнять за один проход, но методы substitute и updateVariables выделены для логического и структурного разденения на фазы.

В результате createPreprocessedPipelineString или вылетает исключение, которое обрабатывается в readExecPrintLoop.run() или возвращается массив комманд, которые далее исполняются друг за другом.

## Исполнение
После препроцессинга preprocessedPipelineString попадает в executor где из подготовленных строк создаются и исполняются команды. Executor возвращает pipelineResult или бросает исключение executionError. 

В методе execute мы последовательно проходим по каждой preprocessedCommandString в preprocessedPipelineString. В цикле мы создаем с помощью commandFactory из  preprocessedCommandString сами команды и исполняем их. При этом мы сохраняем результат исполнения текущей команды чтобы передать его следующей команде в качестве input. 

За команды отвечает класс commandBase и его наследники catCommand, echoCommand, wcCommand, pwdCommand, exitCommand и externalCommand. СomandBase имеет метод execute() отвечающий за выполнение команды. При успешном выполнении он возращает commandResult, при ошибке бросает executionError. Передача результата выполения предыдущей команды происходит с помощью метода setInput. 

Если до завершения прохода по циклу была дана команда exit то мы завершаем проход по циклу и возвращаем pipelineResult с флагом exit=true. Иначе если executor не бросил executionError то он сохраняет commandResult последней команды в pipelineResult и возвращает его в readExecPrintLoop.

## Стадии разработки
Разработка будет происходить в два этапа. 

На первом этапе мы реализуем readExecPrintLoop, упрощенную версию preprocessor и упрощенную версию executor. 

В упрощенной версии preprocessor не будет реализована логика подстановок и пайпов. То есть в нем не будет методов substitute и updateVariables. При этом мы будем использовать класс preprocessedPipelineString, однако на первом этапе разработки мы подразумеваем что в нем хранится только одна preprocessedCommandString. 

В упрощенной версии executor мы не реализуем логику прохода по всем preprocessedCommandString в preprocessedPipelineString а просто созадем и исполняем единственную команду, которая хранится в preprocessedPipelineString.

На втором этапе разработки мы реализуем недостающие методы в preprocessor и добавляем логику прохода по всем командам пайпа в executor. 

