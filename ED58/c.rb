if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i

t.times do
  n = gets.to_i
  arr = []
  
  (0..n-1).each do |i|
    arr.push gets.chomp.split(" ").map(&:to_i)+[i]
  end

#  p arr

  arr.sort_by!{|x| [x[0],x[1]]}

#  p arr

  newarr = []

  z = 1

=begin
  done = false
  arr.each_with_index do |x,i|
  	if i+2<n and x[1]>=arr[i+2][0]
  		puts -1
  		done = true
  		break
  	end
  	newarr.push (x+[z])
  	if i<n-1 and not x[1]>=arr[i+1][0]
	  	z = 3-z
	end
  end
=end

  hasone = false
  hastwo = false

  maxtillnow = -1.0/0.0

  arr.each_with_index do |x,i|
    newarr.push (x+[z])
    if z==1
    	hasone = true
    else
    	hastwo = true
    end
    maxtillnow = x[1] if x[1]>maxtillnow
  	if i+1<n and maxtillnow<arr[i+1][0]
#  		good = true
	  	z = 3-z
	end
  end

#  next if done

#  p newarr
  newarr.sort_by!{|x| x[2]}
#  p newarr
#  p hasone
#  p hastwo

  if not (hasone and hastwo)
  	puts -1
  	next
  end


  newarr.each do |x|
  	print x[3]
  	print " "
  end
  puts
end
