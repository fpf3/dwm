{ pkgs, lib, stdenv, fetchurl, libX11, libXinerama, libXft, writeText, patches ? [ ], conf ? null
# update script dependencies
, gitUpdater
}:
let
  fs = lib.fileset;
  colorFiles = builtins.path { path=../../.cache/wal; };
in
stdenv.mkDerivation rec {
  pname = "dwm";
  version = "6.2-fpf3+";
  
  src = ./.;
  
  buildInputs = 
  [
    libX11 
    libXinerama 
    libXft 
  ];

  prePatch = ''
    sed -i "s@/usr/local@$out@" config.mk
  '';

  makeFlags = [ "CC=${stdenv.cc.targetPrefix}cc WALINC=${colorFiles}" ];
}
