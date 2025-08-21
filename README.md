el archivo que usamos es ~/genset/gen.c
para compilarlo: make gen 

ademas
en sudo crontab -e tenemos

@reboot /home/cristobal/genset/gen
0 4 * * * /sbin/shutdown -r +5

al reiniciar corre el compilado gen
y queda corriendo siempre, el loop se actualiza cada 5 segundos
para cerrar proceslo htop y luego sudo kill -o PID
y a las 4 am todos los dias se reinicia el opi

y para pruebas
gpio write 7 1
gpio readall

listo
