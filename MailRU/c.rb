require 'set'
n = gets.to_i

class KG

  def initialize(ind,l,r)
    @ind = ind
    @l = l
    @r = r
  end

  attr_accessor :ind
  attr_accessor :l
  attr_accessor :r
  attr_accessor :val
end

ls = gets.chomp.split(" ").map(&:to_i)
rs = gets.chomp.split(" ").map(&:to_i)

students = []
(0..n-1).each do |i|
  students.push KG.new(i,ls[i],rs[i])
end

newstud = []

students.each_with_index do |student,i|
  
  if student.l>i
    puts "NO"
    exit
  end
  newstud.insert(student.l,student)
end

val = n

newstud.each_with_index do |stud,i|
  students[stud.ind].val = val
  
  unless ((i!=(n-1)) and stud.l+stud.r == newstud[i+1].l+newstud[i+1].r)
    val-=1
  end
end

seen = Array.new

students.reverse.each do |stud|
  k = 0
  seen.each do |seenstud|
    k+=1 if seenstud>stud.val
  end

  if k!=stud.r
    puts "NO"
    exit
  end

  seen.push stud.val
end

puts "YES"
students.each do |stud|
  print "#{stud.val} "
end
puts
