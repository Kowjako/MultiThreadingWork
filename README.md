# Multikino V2 —  wielowątkowe programowanie
Program przedstawia symulacyjny przebieg dnia w kinie Multikino. Na początku są generowani klienci, następnie każdy klient musi kupić bilet, przyjęto założenie że z kasy może skorzystać jeden klient na raz, następnie w kinie jest generowany plan premier, klienci co mają bilety na określoną premierę są wpuszczani do sali i następnie przez ilość czasu trwa film po czym klienci opuszczają salę i wchodzą ci którzy mają bielty na kolejne godziny. Po ukończeniu przedstawienia wszystkich premier kino się zamyka.
## Wykorzystane elementy programowania wielowątkowego  
- ✅ Tworzenie wątkow
- ✅ Poprawne kończenie wątków (join)
- ✅ Wykorzystanie synchronizacji pojedynczego zasobu (kasy) - *mutex*
- ✅ Wykorzystanie synchronizacji dla więlu wątków (sala - 5 klientów) - *semaphore*
- ✅ Asynchroniczne kończenie wątków - inny wątek wysyła sygnał ukończenia

## Wykorzystane biblioteki
 - 📕 PTHREADS
 - 📘 NCURSES
## Teminologia
| Rzeczywistość  | Obiekt  | 
|---|---|
| Klient  | każdy klient przedstawia osobny wątek  | 
| Kasa   | zasob do synchronizacji, tylko jeden klient może się znajdować przy kasie, implementowane za pomocą mutex     |
| Sala  |  zasob do synchronizacji, tylko 5 klientów może się znajdować w sali, implementowane za pomocą semaphore   | 

## Wynik działania

