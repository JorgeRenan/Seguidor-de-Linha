![unifor_logo](https://user-images.githubusercontent.com/32148244/30723505-3ff3405a-9f0e-11e7-81fc-152139920f83.jpg)

# Seguidor-de-Linha
Carro seguidor de linha com controlador PID

# Introdução
Este é um relatório correspondente as práticas de laboratório da disciplina de Robótica do curso de graduação de Engenharia de Controle e Automação da Universidade de Fortaleza. Estas práticas consistem em elaborar um carro autonomo no qual este irá seguir uma linha e completar determinados circuitos, para controle deste carro é obrigatório o uso de controle PID (Proporcional, Integral, Derivativo).

# Fundamentação Teórica
O controlador proporcional integral derivativo, conhecido populamente como controlador PID ou simplesmente PID, é uma estratégia de controle de processos que une as ações derivativa, integral e proporcional, fazendo com que o sinal de erro diminua pela ação proporcional, seja zerado pela ação integral e obtenha uma antencipativa na velocidade pela ação derivativa.

![image](https://user-images.githubusercontent.com/32148244/30890172-37492e3a-a2f9-11e7-8d54-d9a767ae875c.png)

No controle PID cada ação desenvolve uma função determinada.
A ação proporcional elimina as oscilações da variável, tornando o sistema estável, mas não garante que a mesma esteja no valor desejado (setpoint), esse desvio é denominado off-set. A ação proporcional trabalha corrigindo o erro do sistema, multiplicando o ganho proporcional pelo erro, dessa forma agindo com uma maior amplitude de correção a fim de manter a estabilidade da variável.

A ação integral elimina o desvio de off-set, fazendo com que a variável permaneça próximo ao valor desejado para o sistema mesmo após um distúrbio,  ou seja a variável permanece próximo ao set-point mesmo que ocorra uma variação brusca nas condições de operação. A ação integral realiza a integração do erro no tempo, portanto quanto maior for o tempo de permanência do erro no sistema, maior será a amplitude da ação integral.

A ação derivativa tem sua resposta  proporcional à taxa de variação da variável do processo, aumentando a velocidade de resposta do sistema caso a presença do erro seja detectada. Logo, em sistemas de resposta lenta como controle de temperatura, a ação derivativa permite antecipar o aumento do erro e aumentar a velocidade de resposta do sistema. Quando o sistema a ser controlado possui maior velocidade de resposta, como por exemplo controle de rotação de motores e controle de vazão de fluidos, a ação derivativa pode ser desativada, pois não há necessidade de antecipar a resposta ao erro, pois o sistema pode corrigir rapidamente seu valor, para desativar a ação derivativa basta tornar seu valor igual a zero.
É comum a utilização das combinações P+I e P+I+D, de modo geral em sistemas com boa velocidade de resposta como pressão, vazão e rotação de motores. Para obter um controle mais rápido e preciso os sistemas com resposta lenta como os de controle de temperatura devem utilizar o controlador PID.

# Material Utilizado
Para o projeto é utilizado um aruduino que é  uma plataforma de prototipagem eletrônica de hardware livre e de placa única, projetada com um microcontrolador Atmel AVR com suporte de entrada/saída embutido, uma linguagem de programação padrão, a qual tem origem em Wiring, e é essencialmente C/C++.

![image](https://user-images.githubusercontent.com/32148244/30890496-5d0e6976-a2fb-11e7-9221-f2f6f4a966d4.png)

Integrado ao arduino é utilizado uma placa de infravermelho, esta placa contém 3 sensores ópticos ligados lado a lado. Conforme a linha for detectada (ou não), cada sensor enviará ao Arduino as informações sobre a intensidade do sinal infravermelho refletido, e o programa usará essas informações para calcular a velocidade de cada motor.

![image](https://user-images.githubusercontent.com/32148244/30890555-99c9c950-a2fb-11e7-9b60-b21ccccc54d2.png)

Para acionamento das rodas, foi utilizado 2 servo motores, responsavéis pela movimentação do carro.

![image](https://user-images.githubusercontent.com/32148244/30890761-d74d0f48-a2fc-11e7-9dfa-e5fa685cd1b2.png)

A alimentação do arduino e motores foi através de um pack de baterias.

![image](https://user-images.githubusercontent.com/32148244/30890726-9669a0ea-a2fc-11e7-924b-27c59c40a049.png)

# Desenvolvimento
No inicio da programação define-se quais pinos irão ser utilizados no projeto.
![image](https://user-images.githubusercontent.com/32027941/30883629-27b02034-a2e3-11e7-99dc-43647386c345.png)

Após feito isso, faremos a declaração das possíveis variáveis que serão implementadas no programa.
![image](https://user-images.githubusercontent.com/32027941/30883870-f73be7d4-a2e3-11e7-8155-29fc88930e7e.png)

Para melhor entendimento, solicita-se que as constantes Kp, Ki e Kd comecem zeradas. Quando o primeiro teste for feito, 
é indicado que modifique somente o Kp. Achado o Kp ideal para...

Agora iremos dizer no bloco setup que é uma parte do programa onde se repete apenas no inicialização do Arduino e é lá que iremos dizer a função de cada pino,  configurando-o em entrada de dados ou saída de comandos.
![image](https://user-images.githubusercontent.com/32027941/30884235-39bcb13c-a2e5-11e7-846e-9f68c9d9ec11.png)
Também podemos dar o comando para que as saídas se iniciem zeradas.

O bloco de programação Loop, é onde os dados recebidos e os comandos de resposta serão processados (ou filtrados) para que assim ocorra a movimentação do protótipo. Lá se encontra as variáveis de tempo que serão usadas posteriormente no cálculo do PID. Também será preciso colocar uma lógica de inversão das entradas do sensor para que seja possível o cálculo da resultante deles.
![image](https://user-images.githubusercontent.com/32027941/30884632-bd095882-a2e6-11e7-8248-94b1c5dc8760.png)

Nessa parte do programa, é realizado os cálculos de controle da velocidade dos motores do carrinho. Eles começam com a equação da resultante dos sensores, que será realizada se a soma dos dados de entrada dos sensores forem diferentes de zero de acordo com a inversão dos valores obtidos anteriormente. Depois que feito o cálculo da resultante, é necessário encontrar o erro entre a valor ideal que foi chamado de setpoint e a resultante. Em seguida, faz-se os cálculos de controle do proporcional, integrativo e derivativo, tudo em função do erro achado anteriormente. Dependendo dos valores encontrado pelas variáveis de controle os motores do carrinho irão possuir uma determinda velocidade.
![image](https://user-images.githubusercontent.com/32027941/30884825-6d5729b2-a2e7-11e7-87f0-81bb78423ff9.png)

As linhas que o carrinho irá seguir nem sempre serão lineares, em algum momento existirá curvas a serem feitas e ele deverá estar preparado para quando isso acontecer. Então aplica-se uma lógica de comandos para o movimento, onde a direção será indicada pela velocidade dos motores, que consequentemente dependem das variáveis de controle que são cálculas a partir do erro encontrado. Logo podemos dizer que dependendo do erro indicado o carro irá fazer uma curva ou para direita ou para esquerda ou seguirá em frente.
![image](https://user-images.githubusercontent.com/32027941/30885426-9a8a2248-a2e9-11e7-8545-a45d546c845c.png)

Funções são criadas para facilitar a vida do programador, para que assim ele não precise fazer as mesmas linhas de código várias vezes. Então fazendo jus disso, foram criadas três funções que sinalizam qual a possível direção do carrinho e também a geração do PWM. Dentro das funções foi feito o controle do sentido de rotação do motor, ou seja, em alguns momentos os motores rotacionaram em sentidos iguais e em outros poderam estar em sentidos diferentes. A rotação diferente dos motores significa que ele esta em uma curva, e isso se faz necessario para que ele não saia da bitola da linha seguida.
![image](https://user-images.githubusercontent.com/32027941/30885618-527bbec0-a2ea-11e7-8611-8c0df927498c.png)
![image](https://user-images.githubusercontent.com/32027941/30885726-cebab91e-a2ea-11e7-8e88-03a688049471.png)
Haverá situações onde será necessário a utilização de ganhos nas velocidades do motor. Especificamente, será quando as velocidades dos motores forem menores que zero ou pelo valor escolihdo para o controle.

# Teste e Resultados

Segue imagens do protótipo pronto:

![p_20170919_204636](https://user-images.githubusercontent.com/32148244/30933070-ce455dbc-a39f-11e7-9a3f-11a366e967d3.jpg)

![p_20170919_204646](https://user-images.githubusercontent.com/32148244/30933071-ce4b0488-a39f-11e7-9ea5-f43e4a5ad919.jpg)

Segue link dos vídeos da realização do teste final:

https://youtu.be/NQxjA7YswCo

https://youtu.be/DsVc7cPSmqg

# Conclusão
Na disciplina de robótica, utilizando os conhecimentos adquiridos nesta disciplina e durante o curso de engenharia de controle e automação, podemos montar e programar este protótipo com êxito. Fazendo com que ele realizasse os três circuitos, que foram utilizados como obtenção parcial da nota, com perfeição e aplicando controle PID para realização dos ajustes para cada pista.
