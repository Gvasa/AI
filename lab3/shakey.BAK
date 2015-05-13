% Author:
% Date: 2015-05-13

% acts
act( go(X,Y),  %action name
     [robot(S), at(S,X), on(S,floor), connection(X, C), connection(Y, C), diff(X,Y)],   %preconditions
     [at(K,X)],                                    %remove
     [at(K,Y)]                                      %add
     ).

act( push(B,X,Y), %Action name
     [robot(S), block(B), at(S,X), at(B,X), on(S,floor), connection(X,C), connection(Y,C), light(C,on), diff(X,Y)],          %preconditions
     [at(S,X), at(B,X)],          %remove
     [at(S,Y), at(B,Y)]           %add
     ).

act( climbUp(B),
     [robot(S), block(B), at(S,X), at(B,X), on(S,floor)],     % preconditions
     [on(S,floor)],                                           % remove
     [on(S,block)]                                                % add
     ).
     
act( climbDown(B),
     [robot(S), block(B), at(S,X), at(B,X), on(S,block)],         % preconditions
     [on(S,block)],                                               % remove
     [on(S,floor)]                                            % add
     ).

act( turnOn(L),
     [robot(S), on(S,block), at(S,Position), switch(Position, off), connection(Position, Room)],   % preconditions
     [light(Room, off), switch(Position, off)],                                                      % remove
     [light(Room, on), switch(Position, on)]                                                       % add
     ).

act( turnOff(L),
     [robot(S), on(S,block), at(S,Position), switch(Position, on), connection(Position, Room)],   % preconditions
     [light(Room, on), switch(Position, on)],                                                      % remove
     [light(Room, off), switch(Position, off)]                                                       % add
     ).
     

%GOAL STATE:
goal_state([
            light(room1, off),
            at(shakey, room1_room)
            ]).
%INITIAL STATE:

initial_state([
               %Shakey börjar i
               robot(shakey),
               at(shakey, room1_room),
               on(shakey, floor),

               %alla block är i room1 från början
               block(block1),
               block(block2),
               block(block3),
               block(block4),
               at(block1, room1_room),
               at(block2, room2_room),
               at(block3, room3_room),
               at(block4, room4_room),

               %Ljus är på i room1 och room4

               switch(room1_switch, on),
               switch(room2_switch, on),
               switch(room3_switch, on),
               switch(room4_switch, on),
               light(room1, on),
               light(room2, on),
               light(room3, on),
               light(room4, on),
               light(corridor, on),
               

               connection(room1_switch, room1),
               connection(room1_room, room1),
               connection(room1_door, room1),
               
               connection(room2_switch, room2),
               connection(room2_room, room2),
               connection(room2_door, room2),
               
               connection(room3_switch, room3),
               connection(room3_room, room3),
               connection(room3_door, room3),
               
               connection(room4_switch, room4),
               connection(room4_room, room4),
               connection(room4_door, room4),
               
               connection(room1_door, corridor),
               connection(room2_door, corridor),
               connection(room3_door, corridor),
               connection(room4_door, corridor)
               
              ]).
