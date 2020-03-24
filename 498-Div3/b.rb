nk = gets.chomp.split(" ").map(&:to_i)
arr = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]
maxarr = [[0,-1]]
kmin = 0

arr.each_with_index do |x,i|
  if x>=maxarr[-1][0]
    if maxarr.length == k
      maxarr.pop
    end
    maxarr.push([x,i])
    maxarr.sort_by!{|z| z[0]}.reverse!
  end
end

#p maxarr

printarr=[]
maxarr.sort_by!{|z| z[1]}

sum = 0
prev = 0
maxarr.each do |x|
  sum += x[0]
  printarr.push(x[1]-prev+1)
  prev = x[1]+1
end

#p printarr
puts sum
if k>1
  printarr.pop
  printarr.push(n-printarr.inject(:+))
else
  printarr =  [n]
end
printarr.each{|x| print "#{x} "}
puts
