# Usean alkion pikajärjestäminen

<img src="dokumentaatio/png/dualpivot.png" width="750">

Pikajärjestäminen on ehkä käytetyin järjestämisalgoritmi. Se toimii kaikenlaisen datan kanssa ja on yleensä kaikkein nopein menetelmä varsinkin suurilla syötteillä. Pikajärjestäminen on monien ohjelmointiympäristöjen (Java, C++) pääasiallinen järjestämisalgoritmi.

Pikajärjestämisestä on viimeisten kymmenen vuoden kuluessa tullut uusia kehitelmiä, joilla on saatu tehokkuutta kasvatettua entisestään. Usean jakoalkion järjestämisalgoritmit ovat jo yleisessä käytössä, mutta parempia algoritmeja on edelleen kehitteillä.

Tässä tutkielmassa tarkastellaan eri pikajärjestämisalgoritmeja sekä niiden tehokkuuden riippuvuutta eri tekijöistä. Tehokkuuden arvioinnissa on myös otettava huomioon, miten hyvin algoritmi käyttää hyväksi tietokoneen resursseja. Usean jakoalkion pikajärjestämisalgoritmien tehokkuuden lisäyksen on osoitettu johtuvan suurimmaksi osaksi välimuistin käytön tehostumisesta eikä niinkään algoritmien nopeudesta.

Tutkielmassa tehtiin empiirisiä testejä eri pikajärjestämismenetelmillä. Testien tulokset ovat samansuuntaiset kuin eri menetelmien julkaistut teoreettiset ja kokeelliset tulokset. Teoreettiset tarkastelut osoittavat, että jakoalkioiden määrän optimi on neljä tai viisi. Jakoalkioiden määrää rajoittaa jakoalkioiden optimaalisen valinnan hankaluus.

Empiiriset testit koodattiin C++ -ohjelmointikielen versiolla C++11.

## Dokumentaatio

[Klassinen pikajärjestäminen](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/classic.md)

[Kahden jakoalkion pikajärjestäminen](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/dualpivot.md)

[Kolmen jakoalkion pikajärjestäminen](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/threepivot.md)

[Viiden tai useamman jakoalkion pikajärjestäminen](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/fivepivot.md)

[Empiiriset kokeet](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/testausdokumentti.md)

[Käyttöohje](https://github.com/lautanal/quicksort/blob/master/dokumentaatio/kayttoohje.md)
