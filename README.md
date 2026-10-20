# COLABEDITOR

Editor experimental de niveles inspirado en Geometry Dash 2.2081, con una interfaz oscura y herramientas para bloques, pinchos, monedas y portales.

## Inicio rápido

Abre `index.html` en un navegador moderno o publícalo con GitHub Pages. No requiere un paso de compilación: la biblioteca de Supabase se importa desde CDN.

## Funciones actuales

- Colocar y mover objetos en el escenario.
- Inspector para ajustar posiciones y borrar objetos.
- Cuadrícula, zoom, deshacer y selección de color de fondo.
- Exportar el nivel como JSON.
- Guardar proyectos en Supabase y escuchar actualizaciones del proyecto cuando Realtime esté disponible.

## Supabase

El prototipo está conectado al proyecto Supabase disponible en la cuenta al implementarlo. Ese proyecto aparece con el nombre **MetalGui** y contiene `public.game_projects`; no se encontró un proyecto llamado `colabeditor`. La interfaz usa esa tabla existente, con RLS que limita el acceso a los proyectos del usuario autenticado.

Para guardar desde la interfaz:
1. En Supabase, habilita **Anonymous Sign-Ins** en Authentication si quieres probar sin crear un formulario de registro.
2. Confirma que `public.game_projects` tenga la tabla expuesta a la Data API y Realtime habilitado para cambios de Postgres.
3. Publica el sitio por HTTPS y pulsa **Conectar nube** o **Guardar**.

El navegador solo utiliza la publishable key de Supabase. Nunca pongas una `service_role` o una secret key en el cliente.

## Alcance

Esto es un prototipo web de editor, no un mod binario inyectable en Geometry Dash ni una integración con el editor nativo del juego. La colaboración es básica a nivel de proyecto; para edición multiusuario robusta hacen falta cursores/presencia, conflictos de edición y un modelo de cambios más granular. Los datos exportados son JSON propio de COLABEDITOR, no un archivo de nivel nativo de Geometry Dash.

## Privacidad y atribución

COLABEDITOR es un proyecto independiente y no está afiliado a RobTop Games.
