s = gets.chomp
t = gets.chomp

slen = s.length
tlen = t.length

tuniq = t.chars.to_a.uniq.length

zerocount = s.count("0")
onecount = slen-zerocount

firstchar = s[0]


def checkposs(bstr,tstr,zero,one)

  zlen = zero.length
  onelen = one.length
#  p "zero"
#  p zero
#  p "one"
#  p one

  k = 0
  bstr.each_char do |ch|
#    p ch
    if ch=='0'
#      p tstr[k..k+zlen-1]
      return false unless tstr[k..k+zlen-1]==zero
      k+= zlen
    else
#      p tstr[k..k+onelen-1]
      return false unless tstr[k..k+onelen-1]==one
      k+= onelen
    end
  end

  return true
end


count = 0

nooffirsts = 1
while s[nooffirsts]==firstchar
  nooffirsts+=1
end

if firstchar == "0"
  firstcount = zerocount
  secondcount = onecount
else
  firstcount = onecount
  secondcount = zerocount
end



(0..tlen-2).each do |possfirst|
  thefirst = t[0..possfirst]
  firstlen = possfirst+1
  

  
  #firstcount*firstlen + secondcount * otherlen = tlen
  
  otherlen = (tlen-(firstcount*firstlen)).to_f/secondcount
  next unless otherlen%1==0
  otherlen = otherlen.to_i
  otherstr = t[nooffirsts*firstlen..nooffirsts*firstlen+otherlen-1]


=begin
  p tlen
  p firstcount
  p firstlen
  p secondcount
  p thefirst
  p otherlen
  p otherstr
  puts
=end


  next if otherstr == thefirst
  next if otherstr.nil?
  next unless thefirst.chars.to_a.uniq.length + otherstr.chars.to_a.uniq.length >= tuniq

  if checkposs(s,t,thefirst,otherstr)
=begin
  p tlen
  p firstcount
  p firstlen
  p secondcount
  p thefirst
  puts
=end
    count += 1
  end
end

puts count
  
