#Maintainer: Ujjwal R. <ujjwal.raj.5798@gmail.com>
pkgname='dree-git'
_pkgname='Dree'
pkgver=v2.0.0.r13.g49a8e4a
pkgrel=1
pkgdesc="One single package for visualization, debugging, and exploration of folder hierarchies"
arch=('x86_64')
url="https://github.com/ujjwall-R/Dree.git"
license=('GPL')
groups=()
depends=()
makedepends=('git')
checkdepends=()
optdepends=()
provides=(dree)
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=("git+$url")
noextract=()
md5sums=('SKIP')

pkgver() {
    cd "$_pkgname"
    git describe --long --tags --abbrev=7 | sed 's/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
    cd "$_pkgname"
    if [ ! -d "compile" ]; then mkdir compile; fi && make clean
}

build() {
    cd "$_pkgname"
    make all
}

package() {
    cd "$_pkgname"
    location=$(readlink -f dree.sh)
    cd ../..
    echo "Add the following line into .bashrc or .zshrc (whichever you use)" > post_install
    echo "alias=$location" >> post_install
}
 
