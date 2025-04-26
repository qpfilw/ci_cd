#!/bin/bash

//удалено в целях анонимности
BOT_TOKEN="" 
USER_ID=""

URL="https://api.telegram.org/bot$BOT_TOKEN/sendMessage"
TEXT="Project:+$CI_PROJECT_NAME%0A%0AJob: $CI_JOB_NAME%0A%0AStatus:+$CI_JOB_STATUS"

curl -s -d "chat_id=$USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
