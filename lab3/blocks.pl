% Blocks World

% actions
:- use_module(library(clpfd)).

object(X) :- X in 1..6.
block(X) :- X in 1..4.
triangle(X) :- X in 5..6.
table(X) :- X in 7.

blue(X) :- X in 1..2.
green(X) :- X in 3 \/ 5.
red(X) :- X in 4 \/ 6.


act( pickup_from_table(X),
     [gripEmpty, clear(X), on(X, 7)],     % preconditions
     [gripEmpty, on(X, 7)],               % remove
     [holding(X)]                             % add
     ):-
     object(X).
     
act( pickup_from_block(X,Y),
     [gripEmpty, clear(X), on(X, Y)],         % preconditions
     [gripEmpty, on(X, Y)],                   % remove
     [holding(X), clear(Y)]                   % add
     ):-
     object(X).

act( putdown_on_table(X),
     [holding(X)],                            % preconditions
     [holding(X)],                            % remove
     [gripEmpty, on(X,7)]                 % add
     ):-
     object(X).
     
act( putdown_on_block(X, Y),
     [clear(Y), holding(X)],         % preconditions
     [clear(Y), holding(X)],         % remove
     [gripEmpty, on(X,Y)]            % add
     ):-
     object(X),
     block(Y).


goal_state([ on(X, Y), on(Y,Z), on(Z,7) ]):-
             triangle(X),
             green(X),
             green(Y),
             blue(Z).
             

initial_state(
     [
            gripEmpty,
            on(6, 7),
            on(3, 7),
            on(4, 7),
            on(2, 7),
            on(1, 4),
            on(5, 2),
            clear(1),
            clear(3),
            clear(5),
            clear(6)
     ]).