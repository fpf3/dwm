# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell rec {
    buildInputs = with pkgs.buildPackages;
    [
      xev
      libX11
      libXft
      libXinerama
      libxcb
      libxcursor
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
