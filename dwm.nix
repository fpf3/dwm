# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
let 
  dwm = pkgs.callPackage ./default.nix {};
in
    pkgs.mkShell {
    nativeBuildInputs = 
    [
      #pkgs.dwm.overrideAttrs (final: prev: { version = "6.2-fpf3+"; src=./dev/dwm; }) 
      dwm
    ];
}
