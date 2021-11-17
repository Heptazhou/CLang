input = strip(readline(), ' ')
input = titlecase(replace(input, r" +" => " "))
input = split(input, " ", limit = 2)
input = input[1][1] * ". " * input[2]
println(input)

