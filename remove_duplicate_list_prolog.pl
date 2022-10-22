member([H|T],N):- H=:=N.
member([H|T],N):- H=\=N, member(T,N).

remove_duplicate([],[]).
remove_duplicate([Head|Tail],Result):-
member(Tail,Head),!,
remove_duplicate(Tail, Result).

remove_duplicate([Head|Tail],[Head|Result]):-
remove_duplicate(Tail, Result).