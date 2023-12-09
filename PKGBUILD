#Maintainer: Ujjwal R. <>
pkgname=dree-git
pkgver=2.0.0
pkgrel=1
epoch=
pkgdesc="One single package for visualization, debugging, and exploration of folder hierarchies"
arch=()
url="https://github.com/ujjwall-R/Dree.git"
license=('GPL')
groups=()
depends=()
makedepends=()
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
validgpkeys=()

pkgver() {
    cd "${_pkgname}"
    printf "2.0.0.r%s.%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"   
}

build() {
    cd "$pkgname-$pkgver"
    ./configure --prefix=/usr
    make all
}

package() {
    cd "$pkgname-$pkgver"
    make DESTDIR="$pkgdir/" install
}
 
