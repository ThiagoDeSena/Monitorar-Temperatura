# Monitoramento de Temperatura Online
![monitorar temperatura](https://github.com/user-attachments/assets/7bee17d7-17d7-41a2-88da-99e8be1411d0)
![Badge Concluído](http://img.shields.io/static/v1?label=STATUS&message=CONCLUÍDO&color=GREEN&style=for-the-badge)
![Badge Linguagem](http://img.shields.io/static/v1?label=LINGUAGEM&message=C++&color=pink&style=for-the-badge)
![Badge ferramenta](http://img.shields.io/static/v1?label=MICRO&message=ESP32&color=black&style=for-the-badge)

## Descrição do projeto 

Monitoramento de temperatura utilizando o microcontrolador EPS32 onde lemos os dados do sensor de temperatura [DALLAS 18B20](https://www.alldatasheet.com/datasheet-pdf/pdf/58557/DALLAS/DS18B20.html) 
e enviamos para o servidor do site [thingspeak](https://thingspeak.com/) para armazenar as informações de temperatura lida no ambiente e gerar um gráfico com os valores recebidos. Ademais, também iremos
controlar o acionamento de uma carga utilizando um módulo relé para acionanar a carga de acordo com a temperatura escolhida.

![image](https://github.com/user-attachments/assets/70ffa136-cb7f-42b7-9a57-4ccbbfedb210)


## Funcionalidades

Monitoramento da temperatura

- Monitora Temperatura.
- Gera gráfico online da temperatura lida.
- Aciona cargas automaticamente de acordo com a temperatura.

## Gráfico em tempo real da Temperatura

https://thingspeak.com/channels/2596090/charts/3?bgcolor=%23ffffff&color=%23d62020&days=1&dynamic=true&results=100&round=1000&type=line

## Tecnologias Utilizadas

:heavy_check_mark: `C++:` Linguagem de programação usada para desenvolver a Lógica. 

:heavy_check_mark: `ThingSpeak:` Site para armazenamos os dados e gerar o gráfico da temperatura.

:heavy_check_mark: `Wi-Fi:` Conecção Wi-Fi do ESP32.

## Desenvolvedores

[<img src="https://avatars.githubusercontent.com/u/110785400?v=4" width=115><br><sub>Thiago De Sena</sub>](https://www.linkedin.com/in/thiago-de-sena-ab5b09179/)


