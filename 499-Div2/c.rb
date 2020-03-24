#require 'bigdecimal'

n = gets.to_f
m = gets.to_f
as = gets.chomp.split(" ").map(&:to_f)
bs = gets.chomp.split(" ").map(&:to_f)

#if as.min <= 1 or bs.min <= 1
#  puts -1
#  exit
#end

j = 0
takenterms = []
(n.to_i*2+1).times {takenterms.push []}
takenterms[0].push 1

term = 0.0

while j < n-1
  newterm = as[j]
#  term += 1/newterm

  #p term
#  p takenterms  

  takenterms.each_with_index do |takentimes,i|
  #  next if takentimes.empty? or i == 0
    takentimes.each do |x|
    #  p ((-1)**(i))*(1/(x*newterm))
      term += ((-1)**(i))*(1/(x*newterm))
    end
  end

  (0..n.to_i*2).each do |i|
    i = n*2-i
#    p i
    takentimes = takenterms[i]
    next if takentimes.empty?
    takentimes.each do |x|
      takenterms[i+1].push x*newterm
    end
  end

  newterm = bs[j+1]
#  term += 1/newterm
  
  #p takenterms  

  takenterms.each_with_index do |takentimes,i|
  #  next if takentimes.empty? or i == 0
    takentimes.each do |x|
  #    p ((-1)**(i))*(1/(x*newterm))
    #  p ((-1)**(i))*(1/(x*newterm))
      term += ((-1)**(i))*(1/(x*newterm))
    end
  end

  (0..n.to_i*2).each do |i|
    i = n*2-i
#    p i
    takentimes = takenterms[i]
    next if takentimes.empty?
    takentimes.each do |x|
      takenterms[i+1].push x*newterm
    end
  end

  #p term
  #p takenterms
  j += 1
end


newterm = as[n-1]
#term += 1/newterm
  
takenterms.each_with_index do |takentimes,i|
 # next if takentimes.empty? or i == 0
  takentimes.each do |x|
   # p ((-1)**(i))*(1/(x*newterm))
    term += ((-1)**(i))*(1/(x*newterm))
  end
end

(0..n.to_i*2).each do |i|
  i = n*2-i
#    p i
  takentimes = takenterms[i]
  next if takentimes.empty?
  takentimes.each do |x|
    takenterms[i+1].push x*newterm
  end
end

newterm = bs[0]
#p newterm
#term += 1/newterm


takenterms.each_with_index do |takentimes,i|
 # next if takentimes.empty? or i == 0
  takentimes.each do |x|
    #p ((-1)**(i))*(1/(x*newterm))
    term += ((-1)**(i))*(1/(x*newterm))
  end
end
=begin
(0..n.to_i*2).each do |i|
  i = n*2-i
#    p i
  takentimes = takenterms[i]
  next if takentimes.empty?
  takentimes.each do |x|
    takenterms[i+1].push x*newterm
  end
end
=end

#p takenterms

#j = 0
#weight = 
#while j < n


ans = ((term/(1-term))*m).to_f
if ans < 0 or ans > 10**9
  puts -1
else
  puts ans
end
