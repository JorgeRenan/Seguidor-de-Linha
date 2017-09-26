![unifor_logo](https://user-images.githubusercontent.com/32148244/30723505-3ff3405a-9f0e-11e7-81fc-152139920f83.jpg)

# Seguidor-de-Linha
Carro seguidor de linha com controlador PID

# Introdução
Este é um relatório correspondente as práticas de laboratório da disciplina de Robótica do curso de graduação de Engenharia de Controle e Automação da Universidade de Fortaleza. Estas práticas consistem em elaborar um carro autonomo no qual este irá seguir uma linha e completar determinados circuitos, para controle deste carro é obrigatório o uso de controle PID (Proporcional, Integral, Derivativo).

# Fundamentação Teórica
O controlador proporcional integral derivativo, conhecido populamente como controlador PID ou simplesmente PID, é uma estratégia de controle de processos que une as ações derivativa, integral e proporcional, fazendo com que o sinal de erro diminua pela ação proporcional, seja zerado pela ação integral e obtenha uma antencipativa na velocidade pela ação derivativa.

# Material Utilizado
lista e fotos

# Desenvolvimento
No inicio da programação defini-se quais pinos irão ser utilizados no projeto.
![image](https://user-images.githubusercontent.com/32027941/30883629-27b02034-a2e3-11e7-99dc-43647386c345.png)

Após feito isso, faremos a declaração das possíveis variáveis que serão implementadas no programa.
![image](https://user-images.githubusercontent.com/32027941/30883870-f73be7d4-a2e3-11e7-8155-29fc88930e7e.png)

Para melhor entendimento, solicita-se que as constantes Kp, Ki e Kd comecem zeradas. Quando o primeiro teste for feito, 
é indicado que modifique somente o Kp. Achado o Kp ideal para...

Agora iremos dizer no bloco setup que é uma parte do programa onde se repete apenas no inicialização do Arduino e é lá que iremos dizer a função de cada pino,  configurando-o em entrada de dados ou saída de comandos.
![image](https://user-images.githubusercontent.com/32027941/30884235-39bcb13c-a2e5-11e7-846e-9f68c9d9ec11.png)
Também podemos dar o comando para que as saídas se iniciem zeradas.

O bloco de programação Loop, é onde os dados recebidos e os comandos de resposta serão processados (ou filtrados) para que assim ocorra a movimentação do carrinho. Lá se encontra as variáveis de tempo que serão usadas posteriormente no cálculo do PID. Também será preciso colocar uma lógica de inversão das entradas do sensor para que seja possível o cálculo da resultante deles.
![image](https://user-images.githubusercontent.com/32027941/30884632-bd095882-a2e6-11e7-8248-94b1c5dc8760.png)

Nessa parte do programa, é realizado os cálculos de controle da velocidade dos motores do carrinho. Eles começam com a equação da resultante dos sensores, que será feito se a soma dos dados de entrada dos sensores forem diferentes de zero de acordo com a inversão dos valores anteriormente. Depois que feito o cálculo da resultante, é necessário que encontra-se o erro entre a valor ideal que foi chamado de setpoint e a resultante. Em seguida, faz-se os cálculos de controle do proporcional, integrativo e derivativo, tudo em função do erro achado anteriormente. Dependendo dos valores encontrado pelas variáveis de controle os motores do carrinho irão possuir uma determinda velocidade.
![image](https://user-images.githubusercontent.com/32027941/30884825-6d5729b2-a2e7-11e7-87f0-81bb78423ff9.png)

As linhas que o carrinho irá seguir nem sempre será lineares, em algum momento existirá curvas a ser feitas e ele deverá estar preparado para quando isso acontecer. Então aplica-se uma lógica de comandos para o movimento, onde a direção será indicada pela velocidade dos motores que consequentemente dependem das variáveis de controle que as mesmas também dependem do erro encontrado. Logo podemos dizer que dependendo do erro indicado o carro irá fazer uma curva ou para direita ou para esquerda ou seguirá em frente.
![image](https://user-images.githubusercontent.com/32027941/30885426-9a8a2248-a2e9-11e7-8545-a45d546c845c.png)

Funções são criadas para facilitar a vida do programador, para que assim ele não precise fazer as mesmas linhas de código várias vezes. Então fazendo jus disso, foram criadas três funções que sinalizam qual a possível direção do carrinho e também a geração do PWM. Dentro das funções foi feito o controle do sentido de rotação do motor, ou seja, em alguns momentos os motores rotacionaram em sentidos iguais e em outros poderam estar em sentidos diferentes. A rotação diferente dos motores significa que ele esta em uma curva, e isso se faz necessario para que ele não saia da bitola da linha seguida.
![image](https://user-images.githubusercontent.com/32027941/30885618-527bbec0-a2ea-11e7-8611-8c0df927498c.png)
![image](https://user-images.githubusercontent.com/32027941/30885726-cebab91e-a2ea-11e7-8e88-03a688049471.png)
Haverá situações onde será necessário a utilização de ganhos nas velocidades do motor. Especificamente, será quando as velocidades dos motores forem menores que zero ou pelo valor escolihdo para o controle.

# Teste e Resultados
Video
# Conclusão
