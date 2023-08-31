# Usean alkion pikajärjestäminen

<img src="dokumentaatio/png/ruutukartta.png" width="750">

Järjestämisalgoritmit ovat olleet keskeinen osa tietojenkäsittelyä informaatioajan alusta alkaen. Algoritmien tehtävänä on järjestää tietojoukon alkiot jonkin loogisen järjestyksen mukaan. Yleensä kyseessä on alkioiden suuruusjärjestys tiettyjen ominaisuuksien perusteella.

Tavoitteena on toteuttaa järjestäminen mahdollisimman tehokkaasti. Järjestämisalgoritmeja voidaan verrata toisiinsa aika- ja tilavaativuuden sekä vakauden perusteella. Aika- vaativuuden vertailuissa on huomioitava sekä keskimääräinen saavutettava nopeus että pahimman tapauksen nopeus.

On helppoa järjestää joukko alkioita ajassa O(n2). Pienellä tietomäärällä tämä nopeus riittää hyvin, mutta suurilla syötteillä tämä on liian hidasta. Suurien syötteiden järjestämiseen on kehitetty tehokkaita rekursiivisia algoritmejä, joilla päästään O(n log n) nopeuteen. Näitä ovat muun muassa lomitusjärjestäminen ja pikajärjestäminen, jotka kehitettiin jo 1940- ja 1950-luvuilla.

Viimeisten kymmenen vuoden aikana on otettu käyttöön uusia muunnoksia rekursiivisista järjestämisalgoritmeista. Lomitusjärjestämisestä on kehitetty edelleen hybridimenetelmä Timsort, joka on käytössä mm. Pythonin kirjastorutiineissa. Klassisesta pikajärjestämisestä on puolestaan kehitetty kahden ja usean jakoalkion pikajärjestämismenetelmiä (dual pivot quicksort, multi pivot quicksort). Java käyttää nykyään pääasiallisena järjestämisalgoritminaan kahden jakoalkion pikajärjestämistä.

## Dokumentaatio

[Tehtävän määrittely](https://github.com/lautanal/tiralabra/blob/master/dokumentaatio/maarittelydokumentti.md)

[Testausdokumentti](https://github.com/lautanal/tiralabra/blob/master/dokumentaatio/testausdokumentti.md)

[Toteutusdokumentti](https://github.com/lautanal/tiralabra/blob/master/dokumentaatio/toteutusdokumentti.md)

[Käyttöohje](https://github.com/lautanal/tiralabra/blob/master/dokumentaatio/kayttoohje.md)

## Releaset

[Loppupalautus](https://github.com/lautanal/tiralabra/releases/tag/Final)

