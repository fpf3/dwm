# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell rec {
    buildInputs = with pkgs; [
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
    
    LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
    
    shellHook = ''
      export DISPLAY=:99
    '';
}
