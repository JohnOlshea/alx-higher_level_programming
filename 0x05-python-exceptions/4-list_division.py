#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    result_list = []

    for i in range(list_length):
        result = 0

        try:
            # Try to perform the division
            result = my_list_1[i] / my_list_2[i]
        except IndexError:
            # Handle index out of range
            print("out of range")
        except (ZeroDivisionError, TypeError):
            # Handle division by 0 and wrong type
            if isinstance(my_list_1[i], (int, float)) and isinstance(my_list_2[i], (int, float)):
                print("division by 0")
            else:
                print("wrong type")
        finally:
            result_list.append(result)

    return result_list
