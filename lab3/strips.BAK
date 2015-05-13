% STRIPS planner
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

plan :-
     initial_state(IS),
     goal_state(GS),
     solve(IS,GS,[],Plan),
     writeNL('--- One Plan ---'),
     printPlan(Plan),
     writeNL('-----------------').


% if Goal is a subset of State, then return Plan
solve(State, Goal, Plan, Plan):- is_subset(Goal, State).

% otherwise, select next action and move to the next state
% \+ denotes negation
solve(State, Goal, Sofar, Plan):-
     act(Action, Precons, Delete, Add),
     is_subset(Precons, State),
     \+ member(Action, Sofar),
     delete_list(Delete, State, Remainder),
     append(Add, Remainder, NewState),
     solve(NewState, Goal, [Action|Sofar], Plan).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% find all plans
allPlans :-
     initial_state(IS),
     goal_state(GS),
     solve(IS,GS,[],Plan),
     writeNL('----- Plan -----'),
     printPlan(Plan),
     writeNLNL('---------------'),
     fail.


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% find the optimal plan  (in case of several, it returns the first found)
bestPlan :-
     initial_state(IS),
     goal_state(GS),
     findall(P, solve(IS,GS,[],P), Plans),
     findBestPlan(Plans, BestPlan, Length),
     write('----- Best Plan (length '), write(Length), writeNL(')'),
     printPlan(BestPlan),
     writeNL('-----------------').

findBestPlan([P|Ps], BestP, LengthP) :-
     length(P, X),
     findBestPlan(Ps, P, X, BestP, LengthP).
              
findBestPlan([], BestPlan, Length, BestPlan, Length) :- !.
findBestPlan([H|T], P, X, BestPlan, Length) :-
     length(H, Y),
     (  Y >= X, !, findBestPlan(T, P, X, BestPlan, Length)
        ;
        findBestPlan(T, H, Y, BestPlan, Length) ).



% AUXILIARY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Check is first list is a subset of the second
is_subset([], _).
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