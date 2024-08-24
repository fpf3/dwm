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
    ];
    
    nativeBuildInputs = with pkgs; [
      dmenu
      feh
      gnumake
      lukesmithxyz-st
      rofimoji
      libclang
      clang-tools
    ];
    
    LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
    
    shellHook = ''
      export DISPLAY=:99
    '';
}
