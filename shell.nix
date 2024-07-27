# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
    pkgs.mkShell {
    nativeBuildInputs = with pkgs.buildPackages;
    [
        dmenu
        feh
        gnumake
        st
        xorg.libX11
        xorg.libXft
        xorg.libXinerama
        xorg.libxcb
    ];
    
    shellHook = ''
      export PATH="$PATH:/home/$USER/bin"
      export DISPLAY=:99
    '';
}
