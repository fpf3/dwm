# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
    buildInputs = 
    with pkgs; [
      dmenu
      feh
      gnumake
      lukesmithxyz-st
      rofimoji
    ];

    nativeBuildInputs = with pkgs.buildPackages;
    [
      xorg.xev
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
