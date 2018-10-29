#!/bin/sh
archive=adwaita.tar
destination=~/.brew/share/icons
curl https://my.mixtape.moe/chznxi.tar --output $archive
tar xvf $archive -C $destination
