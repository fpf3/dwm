{ lib, stdenv, fetchurl, libX11, libXinerama, libXft, writeText, pkgs, patches ? [ ], conf ? null
# update script dependencies
, gitUpdater
}:
let
  fs = lib.fileset;
in
stdenv.mkDerivation rec {
  pname = "dwm";
  version = "6.2-fpf3+";
  
  #src = ./.;
  
  src = fetchGit {
    url = "https://github.com/fpf3/dwm.git";
    ref = "master";
  };
  
  
  buildInputs = [ libX11 libXinerama libXft ];

  prePatch = ''
    sed -i "s@/usr/local@$out@" config.mk
  '';

  makeFlags = [ "CC=${stdenv.cc.targetPrefix}cc" "GITREV=${src.rev}" ];
}
