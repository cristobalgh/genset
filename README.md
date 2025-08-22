el archivo que usamos es ~/genset/gen2.c
para compilarlo: make gen2 

ademas
en sudo crontab -e tenemos

@reboot /home/cristobal/genset/gen2
0 4 * * * /sbin/shutdown -r +5

al reiniciar corre el compilado gen2
y queda corriendo siempre, el loop se actualiza cada 5 segundos
para cerrar proceso htop y luego sudo kill -o PID
y a las 4 am todos los dias se reinicia el opi

para cambiar el carrete en caliente

echo 1 > carrete.txt   # Activa modo carrete
echo 0 > carrete.txt   # Desactiva

y para pruebas
gpio write 7 1
gpio readall

listo
