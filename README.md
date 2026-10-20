# COLABEDITOR

**COLABEDITOR is a Geode mod project for Geometry Dash 2.2081**, focused on bringing collaborative editing tools into the game's native level editor.

> Current status: early C++/Geode scaffold. The in-editor button and popup are implemented as a first UI pass, but this repository has not yet been compiled against the target Geode SDK. Supabase authentication, realtime collaboration, and actual object-change synchronization are not implemented yet.

## Native mod layout

- `mod.json`: Geode mod metadata and target GD versions.
- `CMakeLists.txt`: Geode CMake build target.
- `src/main.cpp`: hooks `EditorUI` and adds a COLAB button that opens the in-game panel.
- `index.html`: earlier standalone web-editor prototype; it is **not** the Geode mod.

## Build

1. Install Geode and its SDK/toolchain for your platform: https://docs.geode-sdk.org/
2. Open this repository in a CMake-capable environment with the Geode SDK configured.
3. Build the `COLABEDITOR` target using the Geode toolchain.
4. Install the resulting mod package into a matching Geometry Dash + Geode installation.
5. Test on GD 2.2081 and check the Geode log before distributing it.

The SDK version and hook signatures must match the installed Geode/GD build. This scaffold is not advertised as a tested or ready-to-install `.geode` package yet.

## Planned collaboration architecture

- Session create/join UI in the editor.
- Supabase Auth for identity and project ownership.
- Supabase tables and Realtime for session state and collaborative events.
- Object-level change events, presence, and conflict handling rather than overwriting a whole level on every edit.

The available Supabase project in the connected account was named **MetalGui**, not `colabeditor`, and its existing `public.game_projects` table is currently used only by the older web prototype. The native C++ mod does not connect to Supabase yet. Before adding writes, the database schema and RLS policies need to be designed for shared sessions and collaborators; the existing per-owner policy is not sufficient for shared editing.

Never embed a Supabase `service_role` or secret key in a client mod. Use only publishable credentials with appropriate RLS, or a trusted server endpoint for privileged operations.

## Attribution

COLABEDITOR is an independent community project and is not affiliated with RobTop Games or the official Geometry Dash team.
