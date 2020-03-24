q = gets.to_i

def f(x)
  ((-1)**(x%2))*x
end

q.times do
  quer = gets.chomp.split(" ").map(&:to_i)
  l = quer[0]
  r = quer[1]

  if (l%2==1 and r%2==0)
    puts (r-l+1)/2
  elsif (l%2==0 and r%2==1)
    puts -1*(r-l+1)/2
  elsif l%2==0 and r%2==0
    puts f(l)+(r-l)/2
  else
    puts f(r)+(r-l)/2
  end
end
