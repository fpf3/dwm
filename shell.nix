# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell rec {
    buildInputs = with pkgs.buildPackages;
    [
      xorg.xev
      xorg.libX11
      xorg.libXft
      xorg.libXinerama
      xorg.libxcb
      gdb
      clang-tools
    ];
    
    nativeBuildInputs = with pkgs; [
      gcc
      dmenu
      feh
      gnumake
      libclang
      lukesmithxyz-st
      rofimoji
    ];
    
    LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
    
    shellHook = ''
      export DISPLAY=:99
    '';
}
