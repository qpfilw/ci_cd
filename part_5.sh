#!/bin/bash

USER_WS1="kylalayl2" # Имя пользователя на целевой машине
HOST_WS1="10.10.0.1" # IP-адрес целевой машины
DIR_WS1="/usr/local/bin" # Директория на целевой машине, куда будут скопированы файлы
BUF_DIR="/tmp" # Временная директория для копирования
SUDO_PASSWORD="1234567890"

echo "Копирование s21_cat на $HOST_WS1:$BUF_DIR"
scp cat/s21_cat "$USER_WS1@$HOST_WS1:$BUF_DIR"
if [ $? -ne 0 ]; then
    echo "Ошибка при копировании s21_cat"
    exit 1
fi

echo "Копирование s21_grep на $HOST_WS1:$BUF_DIR"
scp grep/s21_grep "$USER_WS1@$HOST_WS1:$BUF_DIR"
if [ $? -ne 0 ]; then
    echo "Ошибка при копировании s21_grep"
    exit 1
fi

echo "Перемещение файлов в $DIR_WS1"
ssh "$USER_WS1@$HOST_WS1" "echo \"$SUDO_PASSWORD\" | sudo -S mv $BUF_DIR/s21_cat $DIR_WS1 && echo \"$SUDO_PASSWORD\" | sudo -S mv $BUF_DIR/s21_grep $DIR_WS1"
if [ $? -ne 0 ]; then
    echo "Ошибка при перемещении файлов в $DIR_WS1"
    exit 1
fi

echo "Скрипт завершен успешно!"

