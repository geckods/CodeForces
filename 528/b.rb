nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]

a = 1
possans = 1.0/0.0

while a<=(n**0.5)
  if n%a == 0

    fac1 = a
    fac2 = n/a

    if fac2 < k
      possans = [fac1*k+fac2,possans].min
    end
    if fac1 < k
      possans = [fac2*k+fac1,possans].min
    end
  end
  a += 1
end

puts possans
