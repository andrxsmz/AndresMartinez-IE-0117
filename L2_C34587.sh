#!/bin/bash


if [ "$(id -u)" -ne 0 ]; then
	echo "Error: este script debe ser ejecutado como root" >&2
	exit 1
fi


if [ "$#" -ne 3 ]; then
    echo "Uso: $0 <usuario> <grupo> <ruta_archivo>"
    exit 1
fi

usuario=$1
grupo=$2
archivo=$3


if [ ! -e "$archivo" ]; then
    echo "Error: El archivo $archivo no existe" >&2
    exit 1
fi


if grep -q "^$grupo:" /etc/group; then
    echo "El grupo $grupo ya existe"

else
    groupadd "$grupo"
    echo "Grupo $grupo creado exitosamente"
fi


if id "$usuario" &>/dev/null; then
    echo "El usuario $usuario ya existe"
    usermod -a -G "$grupo" "$usuario"
    echo "Usuario $usuario agregado al grupo $grupo"
else
    useradd -m -G "$grupo" "$usuario"
    echo "Usuario $usuario creado exitosamente y agregado al grupo $grupo"
fi

chown "$usuario:$grupo" "$archivo"
echo "Propiedad de $archivo cambiada a $usuario:$grupo"


chmod 740 "$archivo"
echo "Permisos de $archivo establecidos a 740 (rwxr-----)"
echo "Operación completada exitosamente"
exit 0
