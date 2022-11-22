#### Especificação – Software do sistema embarcado:
O sistema proposto será utilizado para aumentar a autonomia energética e
diminuição dos dados transferidos sem fio de uma estação meteorológica.
O sistema deverá aprender as característica do ambiente e prever qual será o
próximo dado, no servidor este dado também será calculado, se houver acerto na
previsão com o dado medido, dentro de uma margem de erro o dado não
precisará ser enviado.
Havendo discrepância poderá ser recalculado os parâmetros da rede para
melhorar a previsão, isto poderá ser feito no servidor e então enviado para o
sistema embarcado.
O software embarcado deverá ser escrito na linguagem C++, e deverão ser
utilizados os conceitos de programação orientada a objetos, principalmente o uso
de polimorfismo com classes abstratas visando a portabilidade do código (quando
necessário)
O software do microcontrolador deverá registrar um log das operações
realizadas, utilizando uma estrutura de fila para armazenar as informações sobre
os eventos ocorridos. O sistema deverá registrar, pelo menos, dois tipos de
eventos:
• Medição das grandezas (temperatura e umidade)
• Acertos e erros de previsão, com troca de parâmetros com o servidor.
Na ocorrência de cada um desses eventos, deverá ser incluído um novo
nodo na fila contendo: ID do controlador (cada equipamento possui um ID único);
e data/hora do evento (usar o clock/calendar desenvolvido anteriormente).
Para possibilitar a consulta das informações, o log precisará ser transferido
para um computador hospedeiro (desktop ou notebook). Durante o envio do log
para o hospedeiro, a fila deverá ser esvaziada (o log será reinicializado), e os
dados transferidos para outra estrutura de dados no hospedeiro (uma lista, por
exemplo). O software do hospedeiro também deve ser escrito em C++.
A comunicação com o hospedeiro deve ser realizada por intermédio de uma
UART (pode ser utilizado um cabo de conversão UART/USB). Além disso, deve
ser previsto algum meio de comunicação wireless para transferência de dados
para um smartphone.
IMPORTANTE!! Não é necessário implementar o software de comunicação
wireless com o smartphone. Basta deixar indicado na documentação (visando
trabalhos futuros) os módulos necessários para realizar a comunicação (ex.
módulos Bluetooth, wifi, entre outros para o sistema embarcado selecionado).


Especificação – Software do computador e Software do
smartphone:
No hospedeiro (computador ou smartphone), a qualquer instante, um “admin”
poderá realizar as seguintes consultas no log:
• listar todos os eventos ocorridos em um determinado intervalo de datas; e
• obter os dados adquiridos, enviados ou não, em um determinado intervalo de
datas.
O software do hospedeiro deve ser escrito em C++, sendo que no
smartphone poderão ser utilizados dados sintéticos para representar as
informações obtidas do controlador proposto. Não é necessário realizar a
transferência de dados do sistema embarcado para o smartphone, mas é preciso
descrever o hardware que seria necessário para realizar a transferência wireless
(ex. módulo bluetooth, wifi, ...) do sistema embarcado para o smartphone.
Para o caso de um computador (ex. Notebook, desktop), o software deve ser
escrito visando a recepção dos dados via porta serial (com cabo).


#### Especificação – Software do computador e Software do smartphone:

No hospedeiro (computador ou smartphone), a qualquer instante, um “admin”
poderá realizar as seguintes consultas no log:
 - Listar todos os eventos ocorridos em um determinado intervalo de datas;
 - Obter os dados adquiridos, enviados ou não, em um determinado intervalo de datas.

O software do hospedeiro deve ser escrito em C++, sendo que no 
smartphone poderão ser utilizados dados sintéticos para representar as
informações obtidas do controlador proposto. Não é necessário realizar a
transferência de dados do sistema embarcado para o smartphone, mas é preciso
descrever o hardware que seria necessário para realizar a transferência wireless
(ex. módulo bluetooth, wifi, ...) do sistema embarcado para o smartphone.
Para o caso de um computador (ex. Notebook, desktop), o software deve ser
escrito visando a recepção dos dados via porta serial (com cabo).


#### Entrega 1 – Documentação e software do computador

- Relatório descrevendo os três programas, ou seja, sistema embarcado,
  computador (notebook/desktop) e smartphone, incluindo:
 
 - Diagrama de classes (preliminar).

 - Funcionamento dos programas (usar máquinas de estados, fluxogramas, diagramas
    de sequência, e outros diagramas que forem úteis para essa descrição).

 - Descrição dos componentes básicos de hardware e de software (ex. descrição da
   placa ou kit de desenvolvimento a ser utilizado, descrição das bibliotecas necessárias
   para a implementação, compilador e ferramentas de desenvolvimento a serem
   utilizadas para o desenvolvimento dos três programas, entre outros).

- Software do computador (notebook/desktop) implementado e funcionando
em C++. Deve ser entregue uma versão funcional do software a ser executado
no computador/notebook, incluindo a funcionalidade da fila para armazenar as
informações sobre os eventos (log) recebidos via UART.

-  Essa entrega possui um peso de 30% sobre a nota final do projeto.
