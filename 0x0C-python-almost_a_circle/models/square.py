from models.rectangle import Rectangle

class Square(Rectangle):
    """Represent a square."""

    def __init__(self, size, x=0, y=0, id=None):
        """Initialize a new Square.

        Args:
            size (int): The size of the new Square.
            x (int): The x coordinate of the new Square.
            y (int): The y coordinate of the new Square.
            id (int): The identity of the new Square.
        Raises:
            TypeError: If size is not an int.
            ValueError: If size <= 0.
            TypeError: If either of x or y is not an int.
            ValueError: If either of x or y < 0.
        """
        super().__init__(size, size, x, y, id)

    def __str__(self):
        """Return the print() and str() representation of the Square."""
        return "[Square] ({}) {}/{} - {}".format(self.id, self.x, self.y, self.width)

