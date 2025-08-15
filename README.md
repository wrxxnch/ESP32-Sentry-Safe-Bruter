# 🔓 ESP32 Sentry/Master Lock Brute Force

Este projeto usa um ESP32 para executar um ataque de brute force via porta de programação (C1) encontrada em cofres eletrônicos Sentry Safe e Master Lock, explorando vulnerabilidade no protocolo de comunicação serial.

Ao energizar o ESP32, ele começa automaticamente a enviar todos os códigos de 00000 até 99999 tentando abrir o cofre.

# ⚠️ Aviso Legal

Este projeto é apenas para uso autorizado, testes de segurança e pesquisa.
O uso em equipamentos que não sejam seus ou sem permissão explícita é ilegal e pode resultar em penalidades criminais.

# 📦 Materiais Necessários

1 × ESP32 (qualquer modelo com GPIO disponível)

2 fios jumper macho-macho ou macho-fêmea

Acesso ao conector interno do cofre (C1 e GND)

# 🔌 Ligações
Cofre	ESP32
GND	GND
C1	GPIO 4 (padrão no código, pode mudar no #define PIN_C1)

O GND do cofre e do ESP32 devem estar interligados para que a comunicação funcione.

# ⚙️ Funcionamento

Conecte GND → GND e C1 → GPIO 4 do ESP32.

Carregue o código no ESP32 usando Arduino IDE ou PlatformIO.

Ao ligar, o ESP32:

Converte o número da tentativa para 5 dígitos.

Envia comando 0x71 (tentar abrir) para o cofre.

Incrementa o código e repete até chegar a 99999.
