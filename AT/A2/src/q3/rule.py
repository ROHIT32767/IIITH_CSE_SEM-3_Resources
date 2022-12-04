from simulator import *
def rule(cell_value: int, neighbors: "list[int]") -> int: 
    """ Representing the cell values as an integer  
    - 0 is white 
    - 1 is black 
    The return value of the function is the new value the cell must take.  
    """  
    if neighbors[1]==1 or neighbors[6]==1:
        return 1
    return cell_value 
     # Other functionality to run the simulation and render the state