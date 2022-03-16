import cfg

g = cfg.new_grammar()
'''
cfg.add_rule(g, "Start", "a")

print(g)

cfg.add_rule(g, "Start", "A b B")

print(g)'''
print(cfg.split_and_flatten(["a b c", "d e f"]))