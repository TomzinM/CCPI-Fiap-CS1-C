Challenge Sprint de Data Structures and Algorithms.
Grupo do challenge é composto de RMs: 568844, 568798, 569467, 569528, 568973

Lógica do programa:

Primeiramente, quando o programa abre, ele mostra as opções de Registrar Sua Informação, fazer Recarga, ou Sair. Além disso, a tela mostra um aviso falando para se registrar.
Se o usuário quiser sair, ele ja é dado a opção. Se ele apertar Recarga, recebe um aviso de que precisa primeiramente fazer registro.
Quando aperta o botão de registro, é pedido para escrever seu nome completo, e depois confirmar o nome dado novamente. Caso tenha alguma descrepância, é avisado para o usuário, e tera que fazer o registro novamente.
Após confirmar seu nome, é preciso escrever o CPF em que a compra deve ser feita. Se o CPF escrito for mais ou menos do que 11 digitos (quantidade de digitos em um CPF comum), ele avisa o usuário e sai.

Agora que a informação esta registrada, aparece o CPF e Nome da compra na interface. Se alguma das informações estiverem erradas, o usuário pode registrar elas novamente. 
O aviso na interface pedindo para Registrar desaparece, e agora esta liberado a Recarga.

Primeiramente, o programa pede que tipo de carro tem. Entre as opções de Grande, Medio, ou Pequeno. Isso ira determinar o tamanho da sua bateria, e quantas kWH são equivalentes a cada ponto de porcentagem.
Se for escrita alguma letra além das dadas como opção, ira ter que começar a recarga novamente.
Em seguinte, o sistema pede qual porcentagem de energia seu carro está. Subtraindo 100 por esse numero, e multiplicando pela base de kWH por porcentagem escolhido anteriormente, temos quantos kWH sera necessário para uma recarga completa.
Se for colocado um numero que é maior do que 100, ou menor que 0, tera que começar a recarga novamente.
O sistema informa de quanto tempo irá demorar para recarga, e quanto dinheiro isso equivale. Dá a opção de fazer a compra ('Y') ou não prosseguir ainda. ('N'). 
Se Y for escolhido, falará que a compra foi processada. Se N for escolhido (ou qualquer outra letra), sairá da recarga.

Quando terminar a recarga, um alerta aparecera na interface para apertar 3 para Sair do programa. Se o usuário tentar fazer recarga novamente, dira que a compra ja foi feita.
