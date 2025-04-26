#!/bin/bash

BOT_TOKEN="7547379665:AAHnaD6-Olpph_v1qVqNu_jvwaIvSILQuE0"
USER_ID="676075459"

URL="https://api.telegram.org/bot$BOT_TOKEN/sendMessage"
TEXT="Project:+$CI_PROJECT_NAME%0A%0AJob: $CI_JOB_NAME%0A%0AStatus:+$CI_JOB_STATUS"

curl -s -d "chat_id=$USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
