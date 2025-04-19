# Separación del sistema Linux

- Linux separa el system del kernel y del usuario

## Espacio del Usuario:

- Aplicaciones, lineas de comandos, librerías

## Espacio del Kernel:

- Discos, firmware, etc
- Más abajo de la máquina

# Utilidades de Linux en embebidos

- Personalización (ISO configurables)
- Licencias gratis
- Código abierto
- Despliegue fácil

# Nivel del Sistema:

- BSP (Board Support Package) configuración de kernel + Drivers
- DTBs (Device Tree Blobs) parecido a CubeMX, se define qué partes de la memoria se utiliza 
- LKM (Kernel Modules)

# Backend Services:

- init system: systemd, sysvinit, busybox (service handler)
- System daemons

# Niveles de usuarios

1 y 2: muy básico, sin shell
3: Shell pero pocos servicios
4: Multiusuario

# Frontend Interfaces:

- Controladores Gráficos
- Personalización del usuario
  
