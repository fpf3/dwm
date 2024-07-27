# shell for dev and debug
{ pkgs ? import <nixpkgs> {} }:
let 
  dwm = pkgs.callPackage ./debug.nix {};
  #dwm = pkgs.callPackage ./default.nix {};
in
    pkgs.mkShell {
    nativeBuildInputs = 
    [
      dwm
    ];
}
