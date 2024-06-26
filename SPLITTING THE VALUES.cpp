int n, len, s
{
n = len(s)
    for length in range(1, n):  
        first_number = int(s[:length])
        current_number = first_number
        start_index = length
        
        while start_index < n:
            current_number -= 1
            next_number_str = str(current_number)
            next_length = len(next_number_str)
            
            if s[start_index:start_index + next_length] != next_number_str:
                break
            
            start_index += next_length
        
        if start_index == n:
            return True
    
    return False
}
