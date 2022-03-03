import cfg

g = cfg.new_grammar()
'''
cfg.add_rule(g, "Start", "a")

print(g)

cfg.add_rule(g, "Start", "A b B")

print(g)'''
print(cfg.grammar_from_file("story.csv"))