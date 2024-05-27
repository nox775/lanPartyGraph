Acest program se ocupa cu citire unor informatii despre 32 de echipe dintr-un turneu folosind diverse structuri de date din limbajul C.
Cele doua utiliatai ale programului sunt:
a) Crearea unui graf al turneului;
b) Calcularea prestigiului fiecarui echipe pe baza performantelor din turneu;

a):
-Se deschid trei fisierele, doua pentru a stoca informatii si unul din care se citesc datele despre turneu;
-Se adauga din fisierul Input date intr-o lista cu ajutorul functiei "addToListFromFile";
-Se pun datele din lista intr-o coada care se ocupa cu organizarea meciurilor;
-Se creeaza graful "campionat" si se populeaza matricea de adiacenta cu ajutorul "makeGraph";
  --Vor exista 5 runde (log2(32)) , iar pentru fiecare runde se vor organiza meciuri -"makeBattle";
  --Se pun intr-o coada invingatorii respectiv in alta invinsii;
  --"VersusWinner" = compara criteriile dupa care o echipa poate sa castige;
  --Creaza muchie de la echipa infranta la echipa castigatoare;
  --Din coada de invingatori se fac iarasi meciuri;
-Se scrie intr-un fiser Output matricea de adiacenta rezultata;
-Se elibereaza memoria din main.c;
b):
-Din makeGraph , makeBattle se formeaza o lista cu clasamentulu turneului;
-Din coada cu invinsii se adauga elemente la lista turenului in ordinea iesirilor din turneu;
-Se scrie in fisierul de OutputScor echipele dar si prestigiul calculat;

  
