#!/bin/bash

proceso="$1"

$1 &
sleep 1

PID=$(pgrep -n -x "$proceso")

archivo="log_registro.txt"
echo "TIEMPO CPU(%) MEMORIA(KB)" > $archivo


while ps aux | awk '{print $2}' | grep -x "$PID" ; do
	TIEMPO=$(date +%S)

    	USO_MEMORIA=$(ps -p "$PID" -o %cpu,%mem --no-headers)
	echo "$USO_MEMORIA"

    	CPU=$(echo "$USO_MEMORIA" | awk '{print $1}')
    	MEMORIA=$(echo "$USO_MEMORIA" | awk '{print $2}')

    	echo "$TIEMPO $CPU $MEMORIA" >> "$archivo"

    	sleep 1
done

grafico="grafico_plot.gp"

echo "
set title 'Consumo de CPU y Memoria'
set xlabel 'Tiempo (segundos)'
set ylabel 'Consumo%'

plot '$archivo' using 1:2 with lines title 'CPU', \
     '$archivo' using 1:3 with lines title 'Memoria' " > $grafico

if [ -s "$archivo" ]; then
    gnuplot -persist "$grafico"
else
    echo "No hay datos para graficar."
fi
