from simulator import *
def rule(cell_value: int, neighbors: "list[int]") -> int: 
    """ Representing the cell values as an integer  
    - 0 is white 
    - 1 is black 
    The return value of the function is the new value the cell must take.  
    """  
    count=int(0)
    for n in neighbors:
        if n==1:
            count=count+1
    if cell_value==1:
        if count==0 or count==1:
            return 0
        if count==2 or count==3:
            return 1
        if count>3:
            return 0
    elif cell_value==0:
        if count==3:
            return 1
        else:
            return 0
     # Other functionality to run the simulation and render the state