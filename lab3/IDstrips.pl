% STRIPS planner with iterative deepening
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% iterative deepening planner
% if no solution is found at a certain level, the level is increased by 1
plan :-
     initial_state(IS),
     goal_state(GS),
     increase(Level),
     write('Level '),writeNLNL(Level),
     solve(IS,GS,[],Plan,0,Level),
     length(Plan, Length),
     write('----- A Plan (length '), write(Length), writeNL(')'),
     printPlan(Plan),
     writeNL('-------------------------').


% Planner with a fix level (max depth)
% May not be optimal
plan(L) :-
     initial_state(IS),
     goal_state(GS),
     Level is L-1,
     write('Level '),writeNLNL(L),
     solve(IS,GS,[],Plan,0,Level),
     length(Plan, Length),
     write('----- A Plan (length '), write(Length), writeNL(')'),
     printPlan(Plan),
     writeNL('-------------------------').


% if Goal is a subset of State, then return Plan
solve(State, Goal, Plan, Plan, _, _):-
     is_subset(Goal, State), !.

% otherwise, select next action. increase the counter and move to the next state
% \+ denotes negation
solve(State, Goal, Sofar, Plan, Counter, Level):-
     Counter =< Level,
     act(Action, Precons, Delete, Add),
     is_subset(Precons, State),
     \+ member(Action, Sofar),
     delete_list(Delete, State, Remainder),
     append(Add, Remainder, NewState),
     NewCounter is Counter+1,
     solve(NewState, Goal, [Action|Sofar], Plan, NewCounter, Level).



% AUXILIARY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

increase(0).
increase(X) :- increase(Y), X is Y+1.

% Check is first list is a subset of the second
is_subset([], _).
is_subset([diff(A,B)|T], Set):- !, \+ A=B, is_subset(T, Set).
is_subset([H|T], Set):- member(H, Set), is_subset(T, Set).


printPlan([]).
printPlan([H|T]):- printPlan(T), writeNL(H).

% Remove all elements of 1st list from second to create third.
delete_list([], State, State) :- !.
delete_list([H|T], State, Newstate):-
           remove(H, State, Remainder), delete_list(T, Remainder, Newstate).

remove(X, [X|T], T) :- !.
remove(X, [H|T], [H|R]):- remove(X, T, R).

writeNL(X) :- write(X), nl.
writeNLNL(X) :- write(X), nl, nl.