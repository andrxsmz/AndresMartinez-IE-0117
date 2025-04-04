#!/bin/bash

DIRECTORIO="/home/andrxsmz/Downloads"

LOGFILE="/home/andrxsmz/Documents/monitor_log.txt"

touch "$LOGFILE"

inotifywait -m -e create -e modify -e delete "$DIRECTORIO" |
while read -r ruta evento archivo; do
    echo "[$(date)] Evento: $evento en archivo: $archivo" >> "$LOGFILE"
done
