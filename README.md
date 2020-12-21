# watertanks
Street with houses and empty ground. Calculate the minimum number of water tanks that should supply houses on that street.
A water tank can supply two houses if it places in the middle e.g. HTH

For example:
input: string H--H-H
result: return 2 water tanks -> HT-HTH

input: string -HH--H-H--H
result: return 4 water tanks -> THHT-HTH-TH

input: string -HH--HH
result: return -1 since it's not possible to supply all houses with water tanks

input: string -------
result: return 0 since there is no water tank needed
